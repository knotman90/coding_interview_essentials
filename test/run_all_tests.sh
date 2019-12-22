#!/bin/bash


for unit_test in test/bin/test_*
do
		$unit_test
done

echo "DONE!"