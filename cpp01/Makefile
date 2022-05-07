GOALS := all fclean

EXERCISE := $(wildcard ./ex*)

ifeq ($(DEBUG), 1)
DEBUG := DEBUG=1
endif

.PHONY: $(GOALS)
$(GOALS): $(EXERCISE)

.PHONY: $(EXERCISE)
$(EXERCISE):
	$(DEBUG) $(MAKE) -C $@ $(MAKECMDGOALS)
