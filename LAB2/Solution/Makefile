TARGET1=buffersize100
TARGET2=buffersize4096
TARGET3=buffersize8192
TARGET4=buffersize16384
TARGET5=buffersize4096_fsync

all : $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5)
$(TARGET1): fig3_4_bufsize100.o error.o
	$(CC) -o $@ $^ 

$(TARGET2): fig3_4_bufsize4096.o error.o
	$(CC) -o $@ $^ 

$(TARGET3): fig3_4_bufsize8192.o error.o
	$(CC) -o $@ $^ 

$(TARGET4): fig3_4_bufsize16384.o error.o
	$(CC) -o $@ $^ 

$(TARGET5): fig3_4_bufsize4096_fsync.o error.o
	$(CC) -o $@ $^ 
 
fig3_4_bufsize100.o: fig3_4_bufsize100.c
fig3_4_bufsize4096.o: fig3_4_bufsize4096.c
fig3_4_bufsize8192.o: fig3_4_bufsize8192.c
fig3_4_bufsize16384.o: fig3_4_bufsize16384.c
fig3_4_bufsize4096_fsync.o: fig3_4_bufsize4096_fsync.c
error.o: error.c

clean:
	rm -f fig3_4_bufsize100.o fig3_4_bufsize4096.o fig3_4_bufsize8192.o fig3_4_bufsize16384.o fig3_4_bufsize4096_fsync.o error.o $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5)
