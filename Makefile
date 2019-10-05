EXTENSION = nextid
EXTVERSION = 0.1

DATA = $(wildcard sql/$(EXTENSION)--*.sql)
MODULE_big = $(EXTENSION)

OBJS = $(patsubst %.c,%.o,$(wildcard src/*.c))

PG_CPPFLAGS = -I$(libpq_srcdir)
PG_CONFIG = pg_config

PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
