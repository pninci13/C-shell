#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_ARGS 100
#define MAX_PATHS 100
#define MAX_LENGTH 1024

// Função para executar programas externos
void execute_external_command(char **args, char **paths, int num_paths);

// Função para exibir a lista de comandos disponíveis
void display_help();

int main() {
    char input[MAX_LENGTH];
    char *args[MAX_ARGS];
    char *paths[MAX_PATHS];
    int num_paths = 0;

    // Inicializar paths com "/bin" por padrão
    paths[num_paths++] = "/bin";

    // Loop infinito para receber comandos
    while (1) {
        printf("Shell> ");
        if (fgets(input, MAX_LENGTH, stdin) == NULL) {
            // Tratar erro ou EOF
            break;
        }

        // Remover o caractere de nova linha
        input[strcspn(input, "\n")] = '\0';

        // Dividir a entrada em tokens
        char *token = strtok(input, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARGS - 1) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        // Verificar se foi inserido algum comando
        if (args[0] == NULL) {
            continue;
        }

        // Verificar se é um comando interno
        if (strcmp(args[0], "exit") == 0) {
            // Comando "exit"
            exit(0);
        } else if (strcmp(args[0], "cd") == 0) {
            // Comando "cd"
            if (i != 2) {
                fprintf(stderr, "Uso: cd <diretório>\n");
            } else {
                if (chdir(args[1]) != 0) {
                    perror("cd");
                }
            }
        } else if (strcmp(args[0], "path") == 0) {
            // Comando "path"
            num_paths = 0;
            if (args[1] != NULL) {
                token = strtok(args[1], ":");
                while (token != NULL && num_paths < MAX_PATHS - 1) {
                    paths[num_paths++] = token;
                    token = strtok(NULL, ":");
                }
            }
            paths[num_paths] = NULL;
        } else if (strcmp(args[0], "help") == 0) {
            // Comando "help"
            display_help();
        } else if (strcmp(args[0], "clear") == 0) {
            // Comando "clear"
            system("clear");
        } else {
            // Comando externo
            execute_external_command(args, paths, num_paths);
        }
    }

    return 0;
}

void execute_external_command(char **args, char **paths, int num_paths) {
    pid_t pid = fork();
    if (pid == 0) {
        // Processo filho
        // Tentar executar o comando nos caminhos definidos
        for (int i = 0; i < num_paths; i++) {
            char executable[MAX_LENGTH];
            snprintf(executable, MAX_LENGTH, "%s/%s", paths[i], args[0]);
            execv(executable, args);
            if (errno != ENOENT) {
                perror("execv");
                exit(1);
            }
        }
        // Se nenhum caminho funcionar, emitir uma mensagem de erro
        fprintf(stderr, "Comando não reconhecido, digite 'help' para obter mais ajuda\n");
        exit(1);
    } else if (pid < 0) {
        // Erro ao criar o processo filho
        perror("fork");
    } else {
        // Processo pai
        int status;
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
        } else {
            if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                fprintf(stderr, "O comando %s falhou\n", args[0]);
            } else if (WIFSIGNALED(status)) {
                fprintf(stderr, "O comando %s terminou de forma anormal\n", args[0]);
            }
        }
    }
}

void display_help() {
    printf("Lista de comandos disponíveis:\n");
    printf("1. exit - Sai do shell\n");
    printf("2. cd <diretório> - Muda para o diretório especificado\n");
    printf("3. ls - Mostra os arquivos presentes no diretorio atual\n");
    printf("4. path <caminhos separados por :> - Define os caminhos para busca de executáveis\n");
    printf("5. help - Exibe esta lista de comandos\n");
    printf("6. clear - Limpa a tela\n");
    printf("7. cat <arquivo> - Exibe o conteúdo do arquivo\n");
    printf("8. pwd - Exibe o diretório de trabalho atual\n");
    printf("9. Outros comandos externos disponíveis no sistema\n");
}
