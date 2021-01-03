#
all:
	blechc blink.blc
	cp blech/blink.* .
	cp ../include/blech*.h .
	sed -i "s|blech/blink.h|blink.h|g" blink.c
