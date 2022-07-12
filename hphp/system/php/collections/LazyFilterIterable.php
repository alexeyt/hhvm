<?hh

class LazyFilterIterable implements \HH\Iterable {
  use LazyIterable;

  private $iterable;
  private $fn;

  public function __construct($iterable, $fn)[] {
    $this->iterable = $iterable;
    $this->fn = $fn;
  }
  public function getIterator()[] {
    return new LazyFilterIterator($this->iterable->getIterator(), $this->fn);
  }
}
