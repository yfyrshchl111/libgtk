#include <stdlib.h>

#include "lib.h"

void		get_default_treeview_args(t_treeview_arg* args,
					  GtkWidget* parent,
					  t_parent_type type)
{
	gtk_memset(args, 0, sizeof(*args));
	args->trv_data = NULL;
	args->trv_show = TRUE;
	set_default_parent(&args->trv_parent, parent, type);
}

static void	set_args(GtkTreeView* treeview, t_treeview_arg* args)
{
	if (args->trv_data)
		gtk_tree_view_set_model(treeview,
					GTK_TREE_MODEL(args->trv_data));
	else
		gtk_tree_view_set_model(treeview,
					GTK_TREE_MODEL(gtk_list_store_new(1, G_TYPE_STRING)));
}

GtkWidget*	get_new_treeview(t_treeview_arg* args)
{
	GtkWidget*	treeview;

	treeview = gtk_tree_view_new();
	set_args(GTK_TREE_VIEW(treeview), args);
	connect_parent(&args->trv_parent, treeview);
	if (args->trv_show)
		gtk_widget_show(treeview);
	return (treeview);
}

GtkWidget*	get_new_treeview_column(t_treeview_arg* args)
{
	/*GtkTreeViewColumn*	column;
	GtkCellRenderer*	renderer;
	GtkListStore*		store;

	(void)args;
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_new_with_attributes("List items", renderer, "text", 0, NULL);
	store = gtk_list_store_new(1, G_TYPE_STRING);
	gtk_tree_view_set_model(GTK_TREE_VIEW
	return (treeview);*/
	(void)args;
	return (NULL);
}

void		treeview_append_row(GtkWidget* treeview, char* line,
				    int is_allocated)
{
	GtkTreeIter	iter;
	GtkListStore*	data;

	data = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(treeview)));
	gtk_list_store_append(data, &iter);
	gtk_list_store_set(data, &iter, 0, line, -1);
	if (is_allocated)
		free(line);
}