#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

#define TOTAL_OP 10
int opt = 0; // opção selecionada, -1 é um estado invalido




typedef struct
{
                int id;
                GtkWidget *img;
                GtkWidget *label;
                GtkWidget *rButton;
		GtkWidget *container;
}OptRecibo;





// Ativa a primeira janela do programa
void menuPrincipal(GtkApplication *app, gpointer *data);

OptRecibo novo_optRecibo(char imgCaminho[], char label[], int *id)
{

	OptRecibo tmp;

	tmp.id = (*id)++;
	tmp.img = gtk_image_new_from_file(imgCaminho);
	tmp.rButton = gtk_radio_button_new(NULL);
	tmp.container = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,80);
	tmp.label = gtk_label_new(label);
	
	return tmp;	
}



void seleciona_op(GtkRadioButton *btn,gpointer data)
{
	int r;
	
	opt = GPOINTER_TO_INT(data);
	printf("%d\n",opt);
}


//--------------------------------------------------------------------------------------------------------------
int main(int argc , char *argv[])
{
	GtkApplication *gRecibo = gtk_application_new("br.com.GeradorRecibo",G_APPLICATION_FLAGS_NONE);
	
	g_signal_connect(gRecibo,"activate",G_CALLBACK(menuPrincipal),NULL);

	int status = g_application_run(G_APPLICATION(gRecibo),argc,argv);

	g_object_unref(gRecibo);


	return status;

}


void menuPrincipal(GtkApplication *app, gpointer *data)
{
	/*TODO:
	*	Criar uma estrutura que represente várias opções de recibo
	*	Um laço que desenhe todos eles na janela
	*	Esse menu deve levar o usuário a uma janela para um tipo de boleto específico
	*/
	GtkWidget *janela = gtk_application_window_new(app);

	int id = 0; //id de cada opção
	

	//-------------------------------------DESIGN-------------------------------------------

	//Declarando Widgets
	GtkWidget *box_central = gtk_box_new(GTK_ORIENTATION_VERTICAL,10);

	GtkWidget *header = gtk_box_new(GTK_ORIENTATION_VERTICAL,0) ;
	
	GtkWidget *foot = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0) ;
			
	GtkWidget *botao_confirma = gtk_button_new_with_label("Prosseguir");

	GtkWidget *botao_cancela = gtk_button_new_with_label("Configurações");

	GtkWidget *botao_ajuda = gtk_button_new_with_label("  Ajuda  ");

	GtkWidget *frame = gtk_frame_new("Escolha um estilo de Recibo");
	
	GtkWidget *frameRecentes = gtk_frame_new("Recentes");
	
	GtkWidget *janelaInterna = gtk_scrolled_window_new (NULL,NULL);

	GtkWidget *opcoes_linhas = gtk_box_new(GTK_ORIENTATION_VERTICAL,40);

	OptRecibo lista[TOTAL_OP];







	
	//----------------------------------HEADER-----------------------------------------------

	gtk_box_pack_start(GTK_BOX(header),frame,1,1,0);

	gtk_box_pack_start(GTK_BOX(header),frameRecentes,0,1,0);

	gtk_frame_set_label_align(GTK_FRAME(frame),0.5,0.5);	
	
	gtk_container_add(GTK_CONTAINER(frame),janelaInterna); 








	

	//-------------------------------OPÇÔES DE RECIBO-------------------------------------	
		
	gtk_container_add(GTK_CONTAINER(janelaInterna),opcoes_linhas);

	
	lista[id] = novo_optRecibo("234.png","Recibo Básico:\n\tCliente\n\tCobrador\n\tValor Total\n\tetc",&id);
	lista[id] = novo_optRecibo("234.png","Recibo Básico:\n\tCliente\n\tCobrador\n\tValor Total\n\tetc",&id);
	lista[id] = novo_optRecibo("234.png","Recibo Básico:\n\tCliente\n\tCobrador\n\tValor Total\n\tetc",&id);
    lista[id] = novo_optRecibo("234.png","Recibo Básico:\n\tCliente\n\tCobrador\n\tValor Total\n\tetc",&id);
    lista[id] = novo_optRecibo("234.png","Recibo Básico:\n\tCliente\n\tCobrador\n\tValor Total\n\tetc",&id);
    lista[id] = novo_optRecibo("234.png","Recibo Básico:\n\tCliente\n\tCobrador\n\tValor Total\n\tetc",&id);
    lista[id] = novo_optRecibo("234.png","Recibo Básico:\n\tCliente\n\tCobrador\n\tValor Total\n\tetc",&id);	
	lista[id] = novo_optRecibo("234.png","Recibo Básico:\n\tCliente\n\tCobrador\n\tValor Total\n\tetc",&id);

	
	
	int i;
	gpointer Data;
	for(i = 0; i < id ; i++)
	{
		gtk_box_pack_start(GTK_BOX(lista[i].container),lista[i].rButton,0,1,1);
		
		gtk_box_pack_start(GTK_BOX(lista[i].container),lista[i].img,0,1,1);

        gtk_box_pack_start(GTK_BOX(lista[i].container),lista[i].label,0,1,1);

		gtk_box_pack_start(GTK_BOX(opcoes_linhas),lista[i].container,0,1,1);

		if(i > 0)
		{
			gtk_radio_button_set_group(GTK_RADIO_BUTTON(lista[i].rButton),gtk_radio_button_get_group(GTK_RADIO_BUTTON(lista[0].rButton)));
		}
		
		//TODO : Implementar sinais

		Data = GINT_TO_POINTER(lista[i].id);
		
		g_signal_connect(lista[i].rButton,"clicked",G_CALLBACK(seleciona_op),Data);
		
	}
	






	//-----------------------------------FOOOT-----------------------------------------------
	
	gtk_box_pack_start(GTK_BOX(foot),botao_ajuda,0,1,0);

	gtk_box_pack_start(GTK_BOX(foot),botao_cancela,1,1,1);
        
    gtk_box_pack_start(GTK_BOX(foot),botao_confirma,1,1,1);
		








	//----------------------------------GERAL--------------------------------------------	


	gtk_box_pack_start(GTK_BOX(box_central),header,1,1,10);

	gtk_box_pack_start(GTK_BOX(box_central),foot,0,1,1);

	gtk_container_add(GTK_CONTAINER(janela),box_central);

	gtk_widget_show_all(janela);
}
