run_server: server.o translate.o delete.o writetofile.o modify.o
	gcc ../obj/server.o ../obj/translate.o ../obj/delete.o ../obj/writetofile.o ../obj/modify.o -o ../bin/server

run_client: client.o 
	gcc ../obj/client.o -o ../bin/client

client.o: ../src/client.c
	gcc -o ../obj/client.o -c ../src/client.c

server.o: ../src/server.c
	gcc -o ../obj/server.o -c ../src/server.c

translate.o: ../src/translate.c
	gcc -o ../obj/translate.o -c ../src/translate.c

delete.o: ../src/delete.c
	gcc -o ../obj/delete.o -c ../src/delete.c

writetofile.o: ../src/writetofile.c
	gcc -o ../obj/writetofile.o -c ../src/writetofile.c

modify.o: ../src/modify.c
	gcc -o ../obj/modify.o -c ../src/modify.c

clean:
	@echo"cleaning files....."
	rm ../obj/server.o ../obj/translate.o ../obj/writetofile.o ../obj/writetofile.o ../obj/modify.o ../obj/client.o
