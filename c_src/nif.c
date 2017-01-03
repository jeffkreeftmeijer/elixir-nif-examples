#include "erl_nif.h"

ErlNifResourceType* RESOURCE_TYPE;

typedef struct
{
  int value;
} Resource;

static int load(ErlNifEnv* env, void** priv, ERL_NIF_TERM load_info)
{
  int flags = ERL_NIF_RT_CREATE | ERL_NIF_RT_TAKEOVER;
  RESOURCE_TYPE = enif_open_resource_type(env, "nif", "Resource", NULL, flags, NULL);
  return 0;
}

ERL_NIF_TERM create(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  unsigned int a;
  ERL_NIF_TERM result;
  Resource* resource;

  if(!enif_get_uint(env, argv[0], &a))
  {
    return enif_make_badarg(env);
  }

  resource = enif_alloc_resource(RESOURCE_TYPE, sizeof(Resource));

  result = enif_make_resource(env, resource);
  enif_release_resource(resource);

  resource-> value = a;

  return enif_make_tuple2(env, enif_make_atom(env, "ok"), result);
}

static ErlNifFunc nif_funcs[] = {
  {"create", 1, create}
};

ERL_NIF_INIT(Elixir.Nif, nif_funcs, &load, NULL, NULL, NULL);
