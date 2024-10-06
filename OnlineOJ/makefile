.PHONY:all
all: # @后的makefile操作不显示
	@cd compile_server;\
	make;\
	cd -;\
	cd oj_server;\
	make;\
	cd -;

.PHONY:output #发布功能
output:
	@mkdir -p output/oj_server;\
	mkdir -p output/compile_server;\
	cp -rf compile_server/compile_server output/compile_server;\
	cp -rf compile_server/temp output/compile_server;\
	cp -rf oj_server/oj_server output/oj_server;\
	cp -rf oj_server/conf output/oj_server;\
	cp -rf oj_server/questions output/oj_server;\
	cp -rf oj_server/template output/oj_server;\
	cp -rf oj_server/wwwroot output/oj_server;\

.PHONY:clean
clean:
	@cd compile_server;\
	make clean;\
	cd -;\
	cd oj_server;\
	make clean;\
	cd -;\
	rm -rf output;



