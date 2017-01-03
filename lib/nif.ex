defmodule Nif do
  @on_load :init

  def init do
    :ok = :erlang.load_nif('./priv/nif', 0)
  end

  def sum(_, _) do
    exit(:nif_library_not_loaded)
  end
end
