//
//  NextID
//
//  Copyright (c) 2020 Wellington Marthas
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#include <sys/time.h>

#include "postgres.h"
#include "funcapi.h"

#define OUR_EPOCH 1546304400000

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(next_id);

int64 current_timestamp(void);

Datum next_id(PG_FUNCTION_ARGS) {
    int64 seq_id = PG_GETARG_INT64(0);
    int32 shard_id = PG_GETARG_INT32(1);

    PG_RETURN_INT64(((current_timestamp() - OUR_EPOCH) << 23) | (shard_id << 10) | (seq_id % 1024));
}

int64 current_timestamp(void) {
    struct timeval t;

    gettimeofday(&t, NULL);
    return t.tv_sec * 1000LL + t.tv_usec / 1000;
}
