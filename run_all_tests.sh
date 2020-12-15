#!/bin/bash

for unit_test in test/bin/test_*
do
		$unit_test || exit -1
done

echo "DONE!"