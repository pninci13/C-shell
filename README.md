# Projeto Shell

### Objetivo
* O objetivo deste projeto era criar um shell simples, que conseguisse simular alguns comandos
encontrados em terminais atuais.

Sendo os comandos básicos:
- cd <diretório> - Mudar de diretório
- exit - Sair do shell
- path <diretório>:<diretório>  - Adiciona o diretório ao path de ambiente para setar busca de executavéis.

Comandos extras:
- ls - Lista or arquivos presentes no diretório atual
- ls -a - Lista or arquivos presentes no diretório atual incluindo arquivos ocultos
- ls -l - Lista or aquivos com mais detalhes, mostrando permissões, grupos, tamanho, data de modificação...
- cat <arquivo> - Exibe o conteúdo de um arquivo.
- echo - Printa mensagens ou variavéis.
- pwd - Mostra pro usuário na tela qual o diretório está atualmente.
- help - Mostra comandos disóníveis para o usuário.
- clear - Limpa a tela do shell

### Como compilar?
Clone o repositório e salve em algum local em sua máquina.\Depois de salvo e aberto, abra um terminal e digite:\
`gcc shell.c -o nome_do_outuput` \
`./nome_do_output`

Assim que executar, digite "help" para ver os comandos disponíveis no shell.

**OBS:** Execute em ambiente Linux ou WSL, em ambiente Windows pode vir a ter alguns problemas. 

### Código

* Fizemos as implementações básicas e extras e também adicionamos 2 comandos que não estavam no escopo, para que fosse possível testar os outros comandos de forma eficiente
  e são eles o comando **echo** e **pwd**.
* 

### Autores
1. Julio Moura
2. Pedro Ninci
3. Pedro Bardall
4. Victor Sardinha
