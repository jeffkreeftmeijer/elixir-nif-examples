ERLANG_PATH = $(shell erl -eval 'io:format("~s", [lists:concat([code:root_dir(), "/erts-", erlang:system_info(version), "/include"])])' -s init stop -noshell)

all:
	gcc -undefined dynamic_lookup -dynamiclib -o priv/nif.so c_src/nif.c -I"$(ERLANG_PATH)"

clean:
	rm  -r "priv/nif.so"
