# compiles blech and copies generated files to the
# current dir (for arduino), renaming includes appropriately
project_name=LED_DotMatrix
all:
	blechc ${project_name}.blc
	cp blech/*.c .
	cp blech/*.h .
	cp ../include/blech*.h .
	sed -i "s|blech/${project_name}.h|${project_name}.h|g" ${project_name}.c
