EXTENSION = nextid
EXTVERSION = 0.1

DATA = $(wildcard sql/$(EXTENSION)--*.sql)
MODULE_big = $(EXTENSION)

OBJS = $(patsubst %.c,%.o,$(wildcard src/*.c))
PG_CPPFLAGS = -std=c99 -Wall -Wextra -Werror -Wno-unused-parameter -Wno-uninitialized -I$(libpq_srcdir)

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
