from random import choice
import sys

def expand(symbol, grammar):
    if symbol.startswith('<'):
        definitions = grammar[symbol]
        expansion = choice(definitions)
        list(map(lambda item: expand(item, grammar), expansion))
    else:
        sys.stdout.write(symbol)
        # print(symbol)


grammar = {'<start>': [['This ', '<object>', 'is here ']],
            '<object>': [['computer '], ['car '], ['assignment ']]
            }
expand('<start>', grammar)
