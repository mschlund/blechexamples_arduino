# compiles blech and copies generated files to the
# current dir (for arduino), renaming includes appropriately
project_name=DHT11_MQTT
all:
	blechc ${project_name}.blc
	cp blech/${project_name}.* .
	cp ../include/blech*.hpp .
	sed -i "s|blech/${project_name}.h|${project_name}.hpp|g" ${project_name}.c
	mv ${project_name}.c ${project_name}.cpp
	mv ${project_name}.h ${project_name}.hpp
	sed -i "s|blech\.h|blech.hpp|g" ${project_name}.hpp
	sed -i "s|blech\.h|blech.hpp|g" ${project_name}.cpp
	rm -r blech/