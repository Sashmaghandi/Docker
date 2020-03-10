vec_class_test: vec_class_test.o Vec.o
	g++ vec_class_test.o Vec.o -o vec_class_test

vec_class_test.o: vec_class_test.cc Vec.h
	g++ -c -g vec_class_test.cc

Vec.o: Vec.cc Vec.h
	g++ -c -g Vec.cc

clean:
	rm Vec.o vec_class_test.o vec_class_test
