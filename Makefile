GOALS = all fclean

MODULES := $(shell find . -type d -regex ".*/cpp0[1-8]*")

ifeq ($(DEBUG), 1)
DEBUG := DEBUG=1
endif

.PHONY: $(GOALS)
$(GOALS): $(MODULES)

.PHONY: $(MODULES)
$(MODULES):
	$(DEBUG) $(MAKE) -C $@ $(MAKECMDGOALS)
