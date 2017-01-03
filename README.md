# elixir-nif-examples

⚠️  Be sure to check out the other [branches](https://github.com/jeffkreeftmeijer/elixir-nif-example/branches) for more examples.

## A Nif with resources

An Elixir library that uses resources to return pointers to native data stuctures from a NIF.

```
$ iex -S mix
Erlang/OTP 19 [erts-8.1] [source] [64-bit] [smp:4:4] [async-threads:10] [hipe] [kernel-poll:false] [dtrace]
Interactive Elixir (1.3.4) - press Ctrl+C to exit (type h() ENTER for help)
iex(1)> {:ok, fourty_two} = Nif.create(42)
{:ok, ""}
iex(2)> {:ok, fourty_three} = Nif.create(43)
{:ok, ""}
iex(3)> fourty_two == "" && fourty_three == "" && fourty_two == fourty_three
true # ⚠️  Resource terms are represented as empty binaries!
iex(4)> Nif.fetch(fourty_three)
43
iex(5)> Nif.fetch(fourty_two)
42
```
