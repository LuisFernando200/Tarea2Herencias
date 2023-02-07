#include <iostream>
using namespace std;

class Mamifero
{
    private:
    string raza;
    int allo;
    int peso;
    string lugar;
    public:
    Mamifero(string, int,int,string);
    void mostrarraza();
    void mostrarjugarao();

    friend Mamifero& operator +(Mamifero &x,Mamifero &x1)
    {
        x.raza=x.raza+x1.raza;
        return x;
    }
    friend Mamifero& operator ==(Mamifero &x,Mamifero &x1)
    {
        x.peso=x.peso+x1.allo;
        return x;
    }
    friend Mamifero& operator !=(Mamifero &x,Mamifero &x1)
    {
        x.allo=x.allo+x1.allo;
        return x;
    }
    friend Mamifero& operator <(Mamifero &x,Mamifero &x1)
   {
    x.lugar=x.lugar+x1.lugar;
    return x;
   }
    friend Mamifero& operator >(Mamifero &x,Mamifero &x1)
   {
    x.lugar=x.lugar+x1.lugar;
    return x;
   }


    protected:
};
Mamifero::Mamifero(string Raza ,int ao ,int pe,string lug){
raza=Raza;
allo=ao;
peso=pe;
lugar=lug;
}

class Felino : public Mamifero
{

    private:
        string mullido;
        string pelaje;
        string alimentacion;
    public:
        Felino(string,int,int,string,string,string,string);
        void mostrarDieta();
           friend Felino& operator +(Felino &x,Felino &x1)
    {
        x.mullido=x.mullido+x1.mullido;
        return x;
    }
    friend Felino& operator ==(Felino &x,Felino &x1)
    {
        x.pelaje=x.pelaje+x1.pelaje;
        return x;
    }
      friend Felino& operator !=(Felino &x,Felino &x1)
    {
        x.alimentacion=x.alimentacion+x1.alimentacion;
        return x;
    }
    protected:

};
Felino::Felino(string Raza,int ao,int pe,string lug,string mull,string pel,string ali) :Mamifero(Raza,ao,pe,lug){
    mullido=mull;
    pelaje=pe;
    alimentacion=ali;
    //ctor
}
class GatoDomestico: public Felino{
    private:
string nombre;
string trabajo;
public:
GatoDomestico(string,int,int,string,string,string,string,string,string);
void empleo();
void cambionom(string);
void cambiocirco(string);
friend GatoDomestico& operator +(GatoDomestico &x,GatoDomestico &x1)
{
     x.nombre=x.nombre+x1.nombre;
     return x;
}
friend GatoDomestico& operator ==(GatoDomestico &x,GatoDomestico &x1)
{
     x.trabajo=x.trabajo+x1.trabajo;
     return x;
}
};
GatoDomestico::GatoDomestico(string Raza,int ao,int pe,string lug,string mull,string pel,string ali,string nom,string tra) : Felino(Raza,ao,pe,lug,mull,pel,ali){
    trabajo=tra;
    nombre=nom;
}
void Mamifero::mostrarraza()
{
    cout<<"La raza es:"<<raza<<endl;
}
void Felino::mostrarDieta()
{
    cout<<"Dieta:"<<alimentacion<<endl;
}
void Mamifero::mostrarjugarao()
{
    cout<<"Año y Fecha\n"<<allo<<"años"<<endl;
    cout<<lugar<<endl;
}
void GatoDomestico::empleo()
{
 cout<<"Nombre del circo:\n"<<trabajo<<endl;
}
void GatoDomestico::cambionom(string n)
{
    nombre=n;
}
void GatoDomestico::cambiocirco(string no)
{
    trabajo=no;
}


int main()
{
    GatoDomestico estrelladecirco("Egipcio",1900,15,"Mexico","Miau","oscuro","pescado","Pedro","Circo el gaton");
     GatoDomestico minino("Siames",2000,18,"Panama","Miau","Claro","Guiscas","Maria","Casa");
    int menu;
    int ops;
    string n;
    string no;
    do{
    cout<<"1.Dieta\n2.Año de nacimineto y lugar\n3.Cambio de dueño de Minino\n4.Raza\n5.Cambiar nombre del circo de EstrellaCirco\n6.Salir\nSeleccione una opcion"<<endl;
    cin>>menu;
    switch(menu)
    {
    case 1:
        cout<<"1.Estrella de circo\n2.Minino\nSeleccione una opcion"<<endl;
        cin>>ops;
        if(ops==1){
        estrelladecirco.mostrarDieta();}
        if(ops==2){
            minino.mostrarDieta();}
        break;
    case 2:
        cout<<"1.Minino\n2.Estrella de circo\nSeleccione una opcion"<<endl;
        cin>>ops;
        if(ops==1){
        estrelladecirco.mostrarjugarao();}
        if(ops==2){
            minino.mostrarjugarao();}

        break;
    case 3:
        cout<<"Nuevo nombre"<<endl;
        cin.ignore();
         getline(cin,n);
        if(ops==1)
            estrelladecirco.cambionom(n);
        break;
    case 4:
        cout<<"1.Minino\n2.Estrella de circo\nSeleccione una opcion"<<endl;
        cin>>ops;
        if(ops==1){
        estrelladecirco.mostrarraza();}
        if(ops==2){
            minino.mostrarraza();}
        break;
    case 5:
        cout<<"Nuevo nombre del circo"<<endl;
        cin.ignore();
         getline(cin,no);
         estrelladecirco.cambiocirco(no);
        break;
    case 6:
        default:
        cout<<"Opcion invalida"<<endl;
        break;
    }
    }while(menu!=6);

}
