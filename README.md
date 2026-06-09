# password-generator-c
Gerador de senhas em C com armazenamento em arquivo, desenvolvido para praticar funções, manipulação de arquivos e geração aleatória de caracteres.

# Gerador de Senhas em C

Projeto desenvolvido durante meus estudos de programação em C e Engenharia de Software.

O programa permite gerar senhas aleatórias personalizadas, salvar as senhas em um arquivo de texto e visualizar todas as senhas já armazenadas.

## Funcionalidades

- Gerar senhas aleatórias
- Escolher o tamanho da senha
- Salvar senhas em arquivo (`senhas.txt`)
- Listar todas as senhas salvas
- Interface simples via terminal

## Tecnologias utilizadas

- Linguagem C
- Biblioteca padrão da linguagem:
  - stdio.h
  - stdlib.h
  - string.h
  - time.h

## Como executar

### Compilar

```bash
gcc main.c -o gerador
```

### Executar

```bash
./gerador
```

## Exemplo de uso

```text
=====================================
         GERADOR DE SENHAS
=====================================
1 - Gerar senha
2 - Mostrar senhas salvas
3 - Sair
=====================================
Escolha uma opcao: 1

Digite o nome da conta/site: GitHub
Digite o tamanho da senha: 12

Senha gerada: 8@Aq#2Lm!xP9
Senha salva com sucesso.
```

## O que pratiquei neste projeto

- Estruturas de repetição
- Estruturas de decisão
- Funções
- Vetores e strings
- Manipulação de arquivos
- Geração de números aleatórios
- Organização de código em C

## Melhorias futuras

- Garantir pelo menos uma letra maiúscula, uma minúscula, um número e um símbolo em cada senha
- Excluir senhas salvas
- Buscar senhas por nome da conta
- Criptografar senhas armazenadas
- Melhorar a validação de entradas

## Autor

Desenvolvido por Guilherme Carvalho como projeto de estudo e prática da linguagem C.
