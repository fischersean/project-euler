.PHONY: init

PDIR = ./problems

init: 
	mkdir -p $(PDIR)/P$(arg1)
	touch $(PDIR)/P$(arg1)/p$(arg1).c
