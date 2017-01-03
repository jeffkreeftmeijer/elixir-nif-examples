# elixir-nif-examples

⚠️  Be sure to check out the other [branches](https://github.com/jeffkreeftmeijer/elixir-nif-example/branches) for more examples.

## A simple NIF

An Elixir example that uses a Nif to implement `Nif.sum/2`.

```
$ iex -S mix
Erlang/OTP 19 [erts-8.1] [source] [64-bit] [smp:4:4] [async-threads:10] [hipe] [kernel-poll:false] [dtrace]
Interactive Elixir (1.3.4) - press Ctrl+C to exit (type h() ENTER for help)
iex(1)> Nif.sum(1,2)
3
```
