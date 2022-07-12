<?hh

class LazyTakeWhileKeyedIterator<Tk, +Tv>
    implements \HH\KeyedIterator<Tk, Tv> {
  private $it;
  private $fn;

  public function __construct($it, $fn)[] {
    $this->it = $it;
    $this->fn = $fn;
  }
  public function __clone() {
    $this->it = clone $this->it;
  }
  public function rewind() {
    $this->it->rewind();
  }
  public function valid() {
    $it = $this->it;
    return ($it->valid() && ($this->fn)($it->current()));
  }
  public function next() {
    $this->it->next();
  }
  public function key() {
    return $this->it->key();
  }
  public function current() {
    return $this->it->current();
  }
}
