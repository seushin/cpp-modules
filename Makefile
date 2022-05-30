GOALS = all fclean

MODULES := cpp01 cpp02 cpp03 cpp04

ifeq ($(DEBUG), 1)
DEBUG := DEBUG=1
endif

.PHONY: $(GOALS)
$(GOALS): $(MODULES)

.PHONY: $(MODULES)
$(MODULES):
	$(DEBUG) $(MAKE) -C $@ $(MAKECMDGOALS)
