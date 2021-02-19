<?hh
<<__EntryPoint>> function main(): void {
require "connect.inc";
$link = ldap_connect_and_bind(test_host(), test_port(), test_user(), test_passwd(), test_protocol_version());
$base = test_base();
insert_dummy_data($link, $base);
$entry = array(
    "description" => "user X"
);

var_dump(
    ldap_mod_replace($link, "cn=userA,$base", $entry),
    ldap_get_entries(
        $link,
        ldap_search($link, "$base", "(description=user X)", array("description"))
    )
);
echo "===DONE===\n";
//--remove_dummy_data($link, $base);
}
