export THOUGHTMAKERS_PATH=/home/madan/thoughtmakers
export LD_LIBRARY_PATH=$THOUGHTMAKERS_PATH/com/thoughtmakers/libs
export THOUGHTMAKERS_MAKE_PATH=$THOUGHTMAKERS_PATH/com/thoughtmakers
cd $THOUGHTMAKERS_MAKE_PATH
make tmlibs
make tmdeploy
make tminit
