defmodule Nif do
  @on_load :init

  def init do
    :erlang.load_nif('./priv/nif', 0)
    :ok
  end

  def sum(_, _) do
    exit(:nif_library_not_loaded)
  end
end
