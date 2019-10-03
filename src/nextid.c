#include <sys/time.h>

#include "postgres.h"
#include "funcapi.h"

#define OUR_EPOCH 1569904749000

PG_MODULE_MAGIC;
 
PG_FUNCTION_INFO_V1(next_id);

Datum next_id(PG_FUNCTION_ARGS) {
    struct timeval t;
 
    int64 seq_no   = PG_GETARG_INT64(0);
    int32 shard_id = PG_GETARG_INT32(1);
    
    gettimeofday(&t, NULL);
 
    PG_RETURN_INT64((((t.tv_sec * 1000) - OUR_EPOCH) << 23) | (shard_id << 10) | (seq_no % 1024));
}
