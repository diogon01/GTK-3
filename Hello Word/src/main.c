#include <gtk/gtk.h>

GtkWidget *g_lbl_hello;
GtkWidget *g_lbl_count;

int main (int argc, char *argv[])
{
    GtkBuilder      *builder;
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    /* Construct a GtkBuilder instance and load our UI description */
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);
    
    /* Connect signal handlers to the constructed widgets. */
    window = GTK_WIDGET (gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    // get pointers to the two labels
    g_lbl_hello = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_hello"));
    g_lbl_count = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_count"));

    //What`s is unref
    g_object_unref(builder);

    /* Show element, this case show de window */
    gtk_widget_show(window);

    gtk_main();

    return 0;

}

/* Function Called After Button is clicked */

void on_btn_hello_clicked()
{
     // Where is unsigned?   
     static unsigned int count = 0;
     char str_count[30] = {0};

     /* Set new string in label g_lbl_hello  */
     gtk_label_set_text(GTK_LABEL(g_lbl_hello), "Hello, agro42!");

     /* Increment count variable */
     count++;

     sprintf(str_count, "%d", count);

     gtk_label_set_text(GTK_LABEL(g_lbl_count), str_count);

}


/* Function when window is close */
void on_window_main_destroy()
{
    gtk_main_quit();
}



