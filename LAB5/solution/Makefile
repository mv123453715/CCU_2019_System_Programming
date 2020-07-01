TARGET1=fig5_4
TARGET2=fig5_5
TARGET3=fig5_5_Full_buffering
TARGET4=fig5_5_Line_buffering
TARGET5=fig5_5_No_buffering

all : $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5)


$(TARGET1): fig5_4.o error.o
	$(CC) -o $@ $^ 

$(TARGET2): fig5_5.o error.o
	$(CC) -o $@ $^ 
 
$(TARGET3): fig5_5_Full_buffering.o error.o
	$(CC) -o $@ $^ 

$(TARGET4): fig5_5_Line_buffering.o error.o
	$(CC) -o $@ $^ 
$(TARGET5): fig5_5_No_buffering.o error.o
	$(CC) -o $@ $^ 

 
fig5_4.o: fig5_4.c
fig5_5.o: fig5_5.c
fig5_5_Full_buffering.o: fig5_5_Full_buffering.c
fig5_5_Line_buffering.o: fig5_5_Line_buffering.c
fig5_5_No_buffering.o: fig5_5_No_buffering.c


clean:
	rm -f fig5_4.o fig5_5.o  error.o fig5_5_Full_buffering.o fig5_5_Line_buffering.o fig5_5_No_buffering.o $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5)
