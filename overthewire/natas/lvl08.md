# Level 8

```
    access the source code
    you will find a php code
    reverse it by:
        <?php
            $secret = "3d3d516343746d4d6d6c315669563362";
            function encodeSecret($secret) {
                return bin2hex(strrev(base64_encode($secret)));
            }
            echo base64_decode(strrev(hex2bin($secret)));
        ?>
    you will get the secret submit it through the form


```
