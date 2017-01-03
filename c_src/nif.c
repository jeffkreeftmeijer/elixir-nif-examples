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

  resource = enif_alloc_resource(RESOURCE_TYPE, sizeof(Resource));

  result = enif_make_resource(env, resource);
  enif_release_resource(resource);

  return enif_make_tuple2(env, enif_make_atom(env, "ok"), result);
}

ERL_NIF_TERM fetch(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  Resource* resource;

  if(!enif_get_resource(env, argv[0], RESOURCE_TYPE, (void**) &resource))
  {
    return enif_make_badarg(env);
  }

  return enif_make_int(env, resource->value);
}

static ErlNifFunc nif_funcs[] = {
  {"create", 0, create},
  {"fetch", 1, fetch}
};

ERL_NIF_INIT(Elixir.Nif, nif_funcs, &load, NULL, NULL, NULL);
