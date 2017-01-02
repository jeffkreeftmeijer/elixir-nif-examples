#include "erl_nif.h"

ERL_NIF_TERM sum(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  int a, b;
  enif_get_int(env, argv[0], &a);
  enif_get_int(env, argv[1], &b);
  return enif_make_int(env, a + b);
}

static ErlNifFunc nif_funcs[] = {
  {"sum", 2, sum}
};

ERL_NIF_INIT(Elixir.Nif, nif_funcs, NULL, NULL, NULL, NULL);
