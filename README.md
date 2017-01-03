# elixir-nif-examples

⚠️  Be sure to check out the other [branches](https://github.com/jeffkreeftmeijer/elixir-nif-example/branches) for more examples.

## A Nif with resources

An Elixir library that uses resources to return pointers to native data stuctures from a NIF.

```
$ iex -S mix
Erlang/OTP 19 [erts-8.1] [source] [64-bit] [smp:4:4] [async-threads:10] [hipe] [kernel-poll:false] [dtrace]
Interactive Elixir (1.3.4) - press Ctrl+C to exit (type h() ENTER for help)
iex(1)> {:ok, resource} = Nif.create
{:ok, ""}
iex(2)> Nif.fetch(resource)
0
iex(3)> {:ok, resource} = Nif.set(resource, 42)
{:ok, ""}
iex(4)> Nif.fetch(resource)
42
```
