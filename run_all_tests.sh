#!/bin/bash

for unit_test in test/bin/test_*
do
		$unit_test || break
done

echo "DONE!"