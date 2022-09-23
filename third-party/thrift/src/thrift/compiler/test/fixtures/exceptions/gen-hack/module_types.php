<?hh
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

/**
 * Original thrift exception:-
 * Fiery
 */
class Fiery extends \TException implements \IThriftSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'message',
      'type' => \TType::STRING,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'message' => 1,
  ];

  const type TConstructorShape = shape(
    ?'message' => ?string,
  );

  const int STRUCTURAL_ID = 1438368398389181198;
  /**
   * Original thrift field:-
   * 1: string message
   */
  public string $message;

  public function __construct(?string $message = null)[] {
    parent::__construct();
    $this->message = $message ?? '';
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'message'),
    );
  }

  public function getName()[]: string {
    return 'Fiery';
  }

  public function clearTerseFields()[write_props]: void {
  }

  public static function getExceptionMetadata()[]: \tmeta_ThriftException {
    return tmeta_ThriftException::fromShape(
      shape(
        "name" => "module.Fiery",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                )
              ),
              "name" => "message",
            )
          ),
        ],
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
      ],
    );
  }

  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

}

/**
 * Original thrift exception:-
 * Serious
 */
class Serious extends \TException implements \IThriftSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'sonnet',
      'type' => \TType::STRING,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'sonnet' => 1,
  ];

  const type TConstructorShape = shape(
    ?'sonnet' => ?string,
  );

  const int STRUCTURAL_ID = 7572301088987666687;
  /**
   * Original thrift field:-
   * 1: string sonnet
   */
  public ?string $sonnet;

  public function __construct(?string $sonnet = null)[] {
    parent::__construct();
    $this->sonnet = $sonnet;
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'sonnet'),
    );
  }

  public function getName()[]: string {
    return 'Serious';
  }

  <<__Override>>
  public function getMessage()[]: string {
    return $this->sonnet ?? '';
  }

  public function clearTerseFields()[write_props]: void {
  }

  public static function getExceptionMetadata()[]: \tmeta_ThriftException {
    return tmeta_ThriftException::fromShape(
      shape(
        "name" => "module.Serious",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                )
              ),
              "name" => "sonnet",
              "is_optional" => true,
            )
          ),
        ],
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
      ],
    );
  }

  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

}

/**
 * Original thrift exception:-
 * ComplexFieldNames
 */
class ComplexFieldNames extends \TException implements \IThriftSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'error_message',
      'type' => \TType::STRING,
    ),
    2 => shape(
      'var' => 'internal_error_message',
      'type' => \TType::STRING,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'error_message' => 1,
    'internal_error_message' => 2,
  ];

  const type TConstructorShape = shape(
    ?'error_message' => ?string,
    ?'internal_error_message' => ?string,
  );

  const int STRUCTURAL_ID = 4419960994551853385;
  /**
   * Original thrift field:-
   * 1: string error_message
   */
  public string $error_message;
  /**
   * Original thrift field:-
   * 2: string internal_error_message
   */
  public string $internal_error_message;

  public function __construct(?string $error_message = null, ?string $internal_error_message = null)[] {
    parent::__construct();
    $this->error_message = $error_message ?? '';
    $this->internal_error_message = $internal_error_message ?? '';
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'error_message'),
      Shapes::idx($shape, 'internal_error_message'),
    );
  }

  public function getName()[]: string {
    return 'ComplexFieldNames';
  }

  <<__Override>>
  public function getMessage()[]: string {
    return $this->internal_error_message ?? '';
  }

  public function clearTerseFields()[write_props]: void {
  }

  public static function getExceptionMetadata()[]: \tmeta_ThriftException {
    return tmeta_ThriftException::fromShape(
      shape(
        "name" => "module.ComplexFieldNames",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                )
              ),
              "name" => "error_message",
            )
          ),
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 2,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                )
              ),
              "name" => "internal_error_message",
            )
          ),
        ],
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
      ],
    );
  }

  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

}

/**
 * Original thrift exception:-
 * CustomFieldNames
 */
class CustomFieldNames extends \TException implements \IThriftSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'error_message',
      'type' => \TType::STRING,
    ),
    2 => shape(
      'var' => 'internal_error_message',
      'type' => \TType::STRING,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'error_message' => 1,
    'internal_error_message' => 2,
  ];

  const type TConstructorShape = shape(
    ?'error_message' => ?string,
    ?'internal_error_message' => ?string,
  );

  const int STRUCTURAL_ID = 4419960994551853385;
  /**
   * Original thrift field:-
   * 1: string error_message
   */
  public string $error_message;
  /**
   * Original thrift field:-
   * 2: string internal_error_message
   */
  public string $internal_error_message;

  public function __construct(?string $error_message = null, ?string $internal_error_message = null)[] {
    parent::__construct();
    $this->error_message = $error_message ?? '';
    $this->internal_error_message = $internal_error_message ?? '';
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'error_message'),
      Shapes::idx($shape, 'internal_error_message'),
    );
  }

  public function getName()[]: string {
    return 'CustomFieldNames';
  }

  <<__Override>>
  public function getMessage()[]: string {
    return $this->internal_error_message ?? '';
  }

  public function clearTerseFields()[write_props]: void {
  }

  public static function getExceptionMetadata()[]: \tmeta_ThriftException {
    return tmeta_ThriftException::fromShape(
      shape(
        "name" => "module.CustomFieldNames",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                )
              ),
              "name" => "error_message",
            )
          ),
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 2,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                )
              ),
              "name" => "internal_error_message",
            )
          ),
        ],
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
      ],
    );
  }

  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

}

/**
 * Original thrift exception:-
 * ExceptionWithPrimitiveField
 */
class ExceptionWithPrimitiveField extends \TException implements \IThriftSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'message',
      'type' => \TType::STRING,
    ),
    2 => shape(
      'var' => 'error_code',
      'type' => \TType::I32,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'message' => 1,
    'error_code' => 2,
  ];

  const type TConstructorShape = shape(
    ?'message' => ?string,
    ?'error_code' => ?int,
  );

  const int STRUCTURAL_ID = 2746197671326593349;
  /**
   * Original thrift field:-
   * 1: string message
   */
  public string $message;
  /**
   * Original thrift field:-
   * 2: i32 error_code
   */
  public int $error_code;

  public function __construct(?string $message = null, ?int $error_code = null)[] {
    parent::__construct();
    $this->message = $message ?? '';
    $this->error_code = $error_code ?? 0;
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'message'),
      Shapes::idx($shape, 'error_code'),
    );
  }

  public function getName()[]: string {
    return 'ExceptionWithPrimitiveField';
  }

  public function clearTerseFields()[write_props]: void {
  }

  public static function getExceptionMetadata()[]: \tmeta_ThriftException {
    return tmeta_ThriftException::fromShape(
      shape(
        "name" => "module.ExceptionWithPrimitiveField",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                )
              ),
              "name" => "message",
            )
          ),
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 2,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_I32_TYPE,
                )
              ),
              "name" => "error_code",
            )
          ),
        ],
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
      ],
    );
  }

  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

}

/**
 * Original thrift exception:-
 * ExceptionWithStructuredAnnotation
 */
class ExceptionWithStructuredAnnotation extends \TException implements \IThriftSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'message_field',
      'type' => \TType::STRING,
    ),
    2 => shape(
      'var' => 'error_code',
      'type' => \TType::I32,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'message_field' => 1,
    'error_code' => 2,
  ];

  const type TConstructorShape = shape(
    ?'message_field' => ?string,
    ?'error_code' => ?int,
  );

  const int STRUCTURAL_ID = 267833845416100769;
  /**
   * Original thrift field:-
   * 1: string message_field
   */
  public string $message_field;
  /**
   * Original thrift field:-
   * 2: i32 error_code
   */
  public int $error_code;

  public function __construct(?string $message_field = null, ?int $error_code = null)[] {
    parent::__construct();
    $this->message_field = $message_field ?? '';
    $this->error_code = $error_code ?? 0;
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'message_field'),
      Shapes::idx($shape, 'error_code'),
    );
  }

  public function getName()[]: string {
    return 'ExceptionWithStructuredAnnotation';
  }

  <<__Override>>
  public function getMessage()[]: string {
    return $this->message_field ?? '';
  }

  public function clearTerseFields()[write_props]: void {
  }

  public static function getExceptionMetadata()[]: \tmeta_ThriftException {
    return tmeta_ThriftException::fromShape(
      shape(
        "name" => "module.ExceptionWithStructuredAnnotation",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                )
              ),
              "name" => "message_field",
            )
          ),
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 2,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_I32_TYPE,
                )
              ),
              "name" => "error_code",
            )
          ),
        ],
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[
        '\thrift\annotation\ExceptionMessage' => \thrift\annotation\ExceptionMessage::fromShape(
          shape(
            "field" => "message_field",
          )
        ),
      ],
      'fields' => dict[
      ],
    );
  }

  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

}

/**
 * Original thrift exception:-
 * Banal
 */
class Banal extends \TException implements \IThriftSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
  ];
  const dict<string, int> FIELDMAP = dict[
  ];

  const type TConstructorShape = shape(
  );

  const int STRUCTURAL_ID = 957977401221134810;

  public function __construct()[] {
    parent::__construct();
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
    );
  }

  public function getName()[]: string {
    return 'Banal';
  }

  public function clearTerseFields()[write_props]: void {
  }

  public static function getExceptionMetadata()[]: \tmeta_ThriftException {
    return tmeta_ThriftException::fromShape(
      shape(
        "name" => "module.Banal",
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
      ],
    );
  }

  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

}

