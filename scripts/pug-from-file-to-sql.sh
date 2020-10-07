#!/bin/bash
########################################
# VARS
# Directory this script resides in
pushd $(dirname "${0}") > /dev/null
DIR=$(pwd -L)
popd > /dev/null
#########################################
# READ USER CONFIGUATION
CONF_FILE=.pug
PUG=${DIR}/../src/command_line/gprom
PUG_CONF=${DIR}/../${CONF_FILE}
source ${DIR}/pug_basic.sh
#########################################
# PARAMETERS
DLFILE="${2}"
LOG="${1}"

if [ $# -lt 2 ]; then
	echo "Description: read a Datalog program with provenance requests and regular path queries from a file and translate into SQL."
	echo " "
    echo "Usage: pass at least two parameters, the first one is the loglevel [0 : NONE up to 5 : TRACE] and the second one is the file storing the input program."
	echo " "
    echo "pug-from-file-to-sql.sh 3 myfile.dl"
    exit 1
fi

if [ ! -f ${DLFILE} ]; then
	echo "File ${DLFILE} not found!"
	exit 1
fi

########################################
# RUN COMMAND
if [[ ${CONNECTION_PARAMS} == *"oracle"* ]]; then
	${PUG} ${LOG} ${CONNECTION_PARAMS} -Boracle.servicename TRUE ${PUG_DL_PLUGINS} -Pexecutor sql -Cattr_reference_consistency FALSE -Cschema_consistency FALSE  -Cunique_attr_names FALSE -treeify-algebra-graphs FALSE -sqlfile ${DLFILE} ${*:3}
fi

if [[ ${CONNECTION_PARAMS} == *"postgres"* ]]; then
	${PUG} ${LOG} ${CONNECTION_PARAMS} ${PUG_DL_PLUGINS} -Pexecutor sql -Cattr_reference_consistency FALSE -Cschema_consistency FALSE  -Cunique_attr_names FALSE -treeify-algebra-graphs -sqlfile ${DLFILE} FALSE ${*:3}
fi
