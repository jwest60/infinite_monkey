## Description

This is an implementation of the [infinite monkey theorem](https://en.wikipedia.org/wiki/Infinite_monkey_theorem) in C++. After entering a word, a virtual monkey will repeatedly attempt to type your word on a virtual typewriter. After the monkey has successfully typed your word, the number of attempts it took the monkey will be output to the screen.

## Usage

The cpp file can be compiled using C++. The executable can be called without any command line arguments. Upon execution, you will be prompted for a word to type. This word may contain letters, numbers, periods, commas, and spaces.

It is recommended that you keep this word small (5 letters or less). This is because the monkey is not very good at typing big words.

## Analysis

There are 39 total characters on the virtual typewriter. Therefore, there is a (1/39)^n chance that the monkey successfully types your word.

For a 6-letter word, the monkey will need approximately 15,625,000,000 attempts before it successfully types your word.
