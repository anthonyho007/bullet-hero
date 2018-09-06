all: build

make_dir:
	mkdir -p build

clean:
	rm -rf build/

build: make_dir
	cd build; cmake .. 
	make -C build

start:
	./build/p2pshoot

.PHONY: make_dir
