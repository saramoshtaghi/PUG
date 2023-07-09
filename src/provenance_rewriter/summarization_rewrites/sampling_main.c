/*-----------------------------------------------------------------------------
 *
 * sampling_main.c
 *			  
 *		
 *		AUTHOR: seokki
 *
 *		
 *
 *-----------------------------------------------------------------------------
 */

#include "common.h"
#include "log/logger.h"
#include "mem_manager/mem_mgr.h"
#include "configuration/option.h"
#include "instrumentation/timing_instrumentation.h"

#include "metadata_lookup/metadata_lookup.h"
#include "model/node/nodetype.h"
#include "utility/string_utils.h"
#include "model/datalog/datalog_model.h"
#include "model/expression/expression.h"
#include "sql_serializer/sql_serializer.h"
#include "provenance_rewriter/prov_utility.h"
#include "provenance_rewriter/prov_rewriter.h"
#include "model/query_operator/query_operator.h"
#include "operator_optimizer/operator_optimizer.h"
#include "model/query_operator/operator_property.h"
#include "model/query_operator/query_operator_dt_inference.h"
#include "model/query_operator/query_operator_model_checker.h"

#include "provenance_rewriter/summarization_rewrites/sampling_main.h"


Node *
rewriteSampleOutput (Node *rewrittenTree, HashMap *summOpts, ProvQuestion qType)
{
	Node *result = NULL;
	int sampleSize = 0;

	if (summOpts != NULL)
	{
		INFO_LOG(" * do sampling rewrite");
		FOREACH_HASH_ENTRY(n,summOpts)
		{
			KeyValue *kv = (KeyValue *) n;
			char *key = STRING_VALUE(kv->key);

			if(streq(key,PROP_SUMMARIZATION_SAMPLE_PROPS))
			{
				List *explSamp = (List *) n->value;

				FOREACH(KeyValue,kv,explSamp)
				{
					char *key = STRING_VALUE(kv->key);

					if(streq(key,PROP_SUMMARIZATION_SAMPLE))
						sampleSize = INT_VALUE(kv->value);
				}
			}
		}
	}

//	DEBUG_LOG("sample size: %f", sampleSize);
//	result = (Node *) rewrittenTree;
//	return result;

	DEBUG_LOG("sampling options are: qType: %s, sample size: %f",
			  ProvQuestionToString(qType), sampleSize);

	if(qType == PROV_Q_WHY)
		//TODO: implement the sampling algorithm
		result = (Node *) rewrittenTree;
		return result;

	if(qType == PROV_Q_WHYNOT)
		INFO_LOG("USE SUMMARIZATION:", result);
		return result;
}

