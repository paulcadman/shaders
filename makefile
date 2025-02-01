raylib-dir = raylib-5.5_macos
build-dir = build
build-dir-exists = $(build-dir)/.exists

.PHONY: all
all: main
	$(build-dir)/main

.PHONY: clean
clean:
	rm -rf $(build-dir)

$(build-dir-exists):
	mkdir -p $(build-dir)
	touch $(build-dir-exists)

$(build-dir): $(build-dir-exists)

main: main.c $(build-dir)
	clang \
	-I$(raylib-dir)/include \
	$(raylib-dir)/lib/libraylib.a \
    -framework CoreVideo \
	-framework IOKit \
	-framework Cocoa \
	-framework GLUT \
	-framework OpenGL \
	main.c \
	-o $(build-dir)/main
