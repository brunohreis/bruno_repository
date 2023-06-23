#include <iostream>
using namespace std;

class contaCorrente{
    protected:
        double saldo;
    public:
        contaCorrente(){
            cout<<"Contrutor da classe conta corrente\n";
        }
        void deposita(double valor){
            this->saldo+=valor;
        }
        virtual void saca(double valor){
            this->saldo-=valor+(0.05*valor);
        }
        double exibeSaldo(){
            return this->saldo;
        }
};

class contaClienteEspecial: public contaCorrente{
    public:
        contaClienteEspecial(){
            cout<<"Construtor da conta de cliente especial\n";
        }
        void saca(double valor){
            this->saldo-=valor+(0.01*valor);
        }
};

int main(){
    contaCorrente *cliente_normal = new contaCorrente();
    cliente_normal->deposita(1000);
    cliente_normal->saca(500);
    cout<<"Saldo cliente normal: R$"<<cliente_normal->exibeSaldo()<<"\n";
    contaClienteEspecial *clienteEspecial = new contaClienteEspecial();
    clienteEspecial->deposita(1000);
    clienteEspecial->saca(500);
    cout<<"Saldo cliente especial: R$"<<clienteEspecial->exibeSaldo()<<"\n";
    return 0;
}