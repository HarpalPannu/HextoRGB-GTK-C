#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
GtkWidget *hexText;
GtkWidget *btnConvert;
GtkWidget *rColor;
GtkWidget *gColor;
GtkWidget *bColor;
void btnConvertClick();
 
int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
	
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "Main.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "Main"));
    gtk_builder_connect_signals(builder, NULL);
	
	gtk_widget_set_size_request(window,300,80);
	
	// g_print ("Hi there! Welcome to GTK\n");
   
    hexText = GTK_WIDGET(gtk_builder_get_object(builder, "hexCodeText"));
    btnConvert = GTK_WIDGET(gtk_builder_get_object(builder, "btnConvert"));
	rColor = GTK_WIDGET(gtk_builder_get_object(builder, "rColor"));
	gColor = GTK_WIDGET(gtk_builder_get_object(builder, "gColor"));
	bColor = GTK_WIDGET(gtk_builder_get_object(builder, "bColor"));
   
	gtk_entry_set_max_length (GTK_ENTRY(hexText),7);
	gtk_entry_set_width_chars (GTK_ENTRY(hexText),9);
	g_signal_connect (btnConvert, "clicked",G_CALLBACK (btnConvertClick),NULL);
	g_signal_connect (window, "destroy",G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);


    g_object_unref(builder);
 
    gtk_widget_show(window);                
    gtk_main();
 
    return 0;
}

void btnConvertClick(){
	
	char colorCode[10];
	sprintf(colorCode, "%s", gtk_entry_get_text(GTK_ENTRY(hexText)));   
	
	char rHex[3];
	strncpy(rHex, colorCode+1, 2);
	rHex[2] = '\0';
	sprintf(rHex, "%d", (int)strtol(rHex, NULL, 16));   
	gtk_entry_set_text(GTK_ENTRY(rColor),rHex);
	
	char gHex[3];
	strncpy(gHex, colorCode+3, 2);
	gHex[2] = '\0';
	sprintf(gHex, "%d", (int)strtol(gHex, NULL, 16));   
	gtk_entry_set_text(GTK_ENTRY(gColor),gHex);
	
	char bHex[3];
	strncpy(bHex, colorCode+5, 2);
	bHex[2] = '\0';
	sprintf(bHex, "%d", (int)strtol(bHex, NULL, 16));   
	gtk_entry_set_text(GTK_ENTRY(bColor),bHex);
	
	
	
	
}
 
// called when button is clicked

 
// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
