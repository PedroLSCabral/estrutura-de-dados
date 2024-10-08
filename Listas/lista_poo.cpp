#include <iostream>

#define N 10

int int_input() {
    int input = 0;

    std::cout << "Digite sua entrada: ";
    std::cin >> input;

    return input;
}

int menu() {
    int escolha;
    std::cout << "\nMenu:\n";
    std::cout << "1. Inserir valor no fim da lista\n";
    std::cout << "2. Remover valor do fim da lista\n";
    std::cout << "3. Remover valor da posicao X\n";
    std::cout << "4. Limpar lista\n";
    std::cout << "5. Mostrar lista\n";
    std::cout << "6. Sair\n";
    std::cout << "Escolha uma opção: ";
    std::cin >> escolha;
    std::cout << "\n";
    return escolha;
}

class lista {
    int cntrl;
    int dados[N];
    public:
        //Construtor
        lista() {
            cntrl = -1;
        }

        int get_controle() {
            return cntrl;
        }
        //Checa se está cheia
        //0 = Cheia
        //1 = Não cheia
        char esta_cheia() {
            if (this->get_controle() == N) 
                return 0;
            return 1;
        }

        //Checa se está vazia
        //0 = Vazia
        //1 = Não vazia
        char esta_vazia() {
            if (this->get_controle() == -1)
                return 0;
            return 1;
        }

        //Inserir valor no fim da lista
        //0 = Execução sem erros
        //1 = Lista cheia
        char inserir_fim(int num) {
            if (this->esta_cheia() == 0)
                return 1;
            
            dados[get_controle()+1] = num;
            cntrl = get_controle() + 1;
            return 0;
        }

        //Remover valor do fim da lista
        //0 = Execução sem erros
        //1 = Lista vazia
        char remover_fim() {
            if (this->esta_vazia() == 0)
                return 1;

            cntrl = get_controle() - 1;
            return 0;
        }

        char remover_meio(int pos) {
            if (this->esta_vazia() == 0)
                return 1;

            if (pos > get_controle())
                return 2;

            for (int i = pos; i < get_controle(); i++) {
                dados[i] = dados[i+1];
            }
            cntrl = cntrl - 1;
            return 0;

        }

        //Limpar a lista
        //0 = Execução sem erros
        //1 = Lista vazia
        char limpar() {
            if (this->esta_vazia() == 0)
                return 1;

            cntrl = -1;
            return 0;
        }
        //Mostrar lista
        //0 = Execução sem erros
        //1 = Lista vazia
        char mostrar_lista() {
            if (this->esta_vazia() == 0)
                return 1;
            
            for (int i = 0; i <= get_controle(); i++)
                std::cout << dados[i] << "\n";
            std::cout << "\n";
            return 0;

        }
        
};

int main() {
    lista l1;
    int escolha, rtrn;

    do {
        escolha = menu();
        printf("\033c"); //Limpa o terminal
        rtrn = -1;

        switch(escolha) { // Lida com o o retorno da função menu
            case 1:
                rtrn = l1.inserir_fim(int_input());
                switch (rtrn) { //Lida com os retornos individuais das funções chamadas pelo menu
                    case 0:
                        std::cout << "\nItem adicionado com sucesso\n";
                        break;
                    case 1:
                        std::cout << "\nLista cheia, acao nao concluida\n";
                        break;
                }
                break;
            case 2:
                rtrn = l1.remover_fim();
                switch(rtrn) {
                    case 0:
                        std::cout << "\nItem removido com sucesso\n";
                        break;
                    case 1:
                        std::cout << "\nLista vazia, acao nao concluida\n";
                        break;
                }
                break;
            case 3:
                rtrn = l1.remover_meio(int_input());
                switch(rtrn) {
                    case 0:
                        std::cout << "\nItem removido com sucesso\n";
                        break;
                    case 1:
                        std::cout << "\nLista vazia, acao nao concluida\n";
                        break;
                    case 2:
                        std::cout << "\nIndice fora do alcance, acao nao concluida\n";
                        break;
                }
                break;
            case 4:
                rtrn = l1.limpar();
                switch(rtrn) {
                    case 0:
                        std::cout << "\nLista limpa com sucesso\n";
                        break;
                    case 1:
                        std::cout << "\nLista vazia, acao nao concluida\n";
                        break;
                }
                break;
            case 5:
                rtrn = l1.mostrar_lista();
                switch(rtrn) {
                    case 0:
                        break;
                    case 1:
                        std::cout << "\nLista vazia, acao nao concluida\n";
                        break;
                }
                break;
            case 6:
                break;
                }
        
        } while (escolha != 6);

    return 0;
}