tmlibs:
	g++ -shared -o ./libs/liblocationutils.so ./src/utils/LocationUtils.cpp
	g++ -shared -o ./libs/liblocationmemstructure.so ./src/location/location_mem_structure.cpp
	g++ -shared -o ./libs/libproductmemstructure.so ./src/product/product_ctlg_mem_structure.cpp

tmdeploy:
	g++ -L ./libs/ ./src/boot/BootLoader.cpp -o ./deploy/bootloader -l locationutils

tminit:
	./deploy/bootloader
