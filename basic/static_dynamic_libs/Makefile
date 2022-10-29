CXX=g++
AR=ar

LIB1_OBJECT:
	$(CXX) -c -fPIC lib1.cpp -o lib1.o
LIB1_STATIC: LIB1_OBJECT
	$(AR) -crv lib1.a lib1.o
LIB1_SHARED: LIB1_OBJECT
	$(CXX) -shared -o lib1.so lib1.o
LIB1: LIB1_STATIC LIB1_SHARED

LIB2_OBJECT:
	$(CXX) -c -fPIC lib2.cpp -o lib2.o
LIB2_STATIC_STATIC: LIB1_STATIC LIB2_OBJECT
	$(AR) crsT lib2.static.a lib1.a lib2.o
LIB2_STATIC_SHARED: LIB1_STATIC
	$(CXX) -fPIC -shared lib2.cpp ./lib1.a -o lib2.static.so
LIB2_SHARED_STATIC: LIB1_SHARED LIB2_OBJECT
	$(AR) crsT lib2.shared.a ./lib1.so lib2.o
LIB2_SHARED_SHARED: LIB1_SHARED
	$(CXX) -fPIC -shared ./lib1.so lib2.cpp ./lib1.so -o lib2.shared.so
LIB2: LIB2_STATIC_SHARED LIB2_STATIC_STATIC LIB2_SHARED_SHARED LIB2_SHARED_STATIC


TEST1_OBJECT:
	$(CXX) -c test1.cpp -o test1.o
TEST1_STATIC: TEST1_OBJECT LIB1_STATIC
	$(CXX) ./test1.o ./lib1.a -o test1.static.exe
TEST1_SHARED: TEST1_OBJECT LIB1_SHARED
	$(CXX) ./test1.o ./lib1.so -o test1.shared.exe
TEST1: TEST1_SHARED TEST1_STATIC

TEST2_OBJECT:
	$(CXX) -c test2.cpp -o test2.o
TEST2_STATIC_STATIC: LIB2_STATIC_STATIC TEST2_OBJECT
	$(CXX) ./test2.o ./lib2.static.a -o test2.static.static.exe
TEST2_STATIC_SHARED: LIB2_STATIC_SHARED TEST2_OBJECT
	$(CXX) ./test2.o ./lib2.static.so -o test2.static.shared.exe
TEST2_SHARED_STATIC: LIB2_SHARED_STATIC TEST2_OBJECT
	$(CXX) ./test2.o ./lib2.shared.a -o test2.shared.static.exe
TEST2_SHARED_SHARED: LIB2_SHARED_SHARED TEST2_OBJECT
	$(CXX) -Wl,-rpath=./ ./test2.o ./lib2.shared.so -o test2.shared.shared.exe
TEST2: TEST2_STATIC_SHARED TEST2_STATIC_STATIC TEST2_SHARED_SHARED TEST2_SHARED_STATIC

clean:
	rm ./*.a ./*.o ./*.so