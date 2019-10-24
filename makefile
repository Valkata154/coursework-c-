test:
	cl /c BinarySearchTree.cpp
	lib /OUT:BST.lib BinarySearchTree.obj
	cl /c test.cpp
	link test.obj BST.lib
	test
	
counter1:
	cl /c BinarySearchTree.cpp
	lib /OUT:BST.lib BinarySearchTree.obj
	cl /c counter.cpp
	link counter.obj BST.lib
	counter single_words_test.txt
	
counter2:
	cl /c BinarySearchTree.cpp
	lib /OUT:BST.lib BinarySearchTree.obj
	cl /c counter.cpp
	link counter.obj BST.lib
	counter sentences_test.txt
	
clean:
	del *.obj
	del *.exe
	del *.asm
	del *.lib
	del *.o