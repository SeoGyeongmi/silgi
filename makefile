market : market.c manager.o product.o
	gcc $^ -o market
manager.o : manager.c
	gcc -c $^
product.o : product.c
	gcc -c $^
clear : 
	rm *.o market
