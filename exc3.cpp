#include <iostream>
using namespace std;
class elevator{
    private:
        int andar_atual;
        int tot_andares;
        int capacidade;
        int pessoas;
    public:
        elevator(int capacidade, int tot_andares){
            cout<<"Construtor da classe elevador\n";
            this->andar_atual=0;
            this->tot_andares=tot_andares;
            this->capacidade=capacidade;
            this->pessoas=0;
        }
        void entra(){
            if(this->pessoas!=this->capacidade){
                this->pessoas++;
            }
            else{
                cout<<"O elevador ja esta lotado, ninguem pode entrar\n";
            }
        }
        void sai(){
            if(this->pessoas>0){
                pessoas--;
            }
            else{
                cout<<"O elevador ja esta vazio\n";
            }
        }
        void sobe(){
            if(this->andar_atual!=this->tot_andares){
                andar_atual++;
            }
            else{
                cout<<"O elevador ja esta no ultimo andar, entao nao pode subir\n";
            }
        }
        void desce(){
            if(this->andar_atual!=0){
                andar_atual--;
            }
            else{
                cout<<"O elevador ja esta no terreo, entao nao pode descer\n";
            }
        }
        int getAndar(){
            return this->andar_atual;
        }
        int getTotAndares(){
            return this->tot_andares;
        }
        int getCapacidade(){
            return this->capacidade;
        }
        int getPessoas(){
            return this->pessoas;
        }

};

int main(){
    int aux_cap, aux_tot_andares;
    string aux="elevador";
    cout<<"Digite a capacidade e o total de andares: ";
    scanf("%d %d", &aux_cap, &aux_tot_andares);
    elevator *elevador = new elevator(aux_cap, aux_tot_andares);
    cout<<"-------------------------------------------------------------------\n";
    cout<<"Modo de interaaco do elevador ativado.\n";
    cout<<"Para subir, digite SOBE, para descer, digite DESCE.\n";
    cout<<"Para alguem entrar, digite ENTRA, para alguem sair, digite SAI.\n";
    cout<<"Para descobrir o andar atual, digite ANDAR.\n";
    cout<<"Para descobrir quantas pessoas tem no elevador, digite PESSOAS\n";
    cout<<"Digite a acao desejada: ";
    cin>>aux;
    while(aux!="FIM"){
        if(aux=="SOBE"){
            elevador->sobe();
        }
        else if(aux=="DESCE"){
            elevador->desce();
        }
        else if(aux=="ENTRA"){
            elevador->entra();
        }
        else if(aux=="SAI"){
            elevador->sai();
        }
        else if(aux=="ANDAR"){
            cout<<"O elevador esta no andar "<<elevador->getAndar()<<"\n";
        }
        else if(aux=="PESSOAS"){
            cout<<"Tem "<<elevador->getPessoas()<<" pessoas no elevador"<<"\n";
        }
        cout<<"Digite a acao desejada: ";
        cin>>aux;
    }
    return 0;
}