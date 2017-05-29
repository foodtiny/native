/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "../network.h"
#include "../string.h"
#include "../common.h"
#include "../vendor.h"
#include "../builtin.h"

/**
 * Etcd Get
 * @param host
 * @param key
 * @return json
 */
char *etcd_get(char *url, char *key) {
	
	if (length_pointer_char(url) == 0 ||
	    length_pointer_char(key) == 0) {
		return "";
	}
	
	char *connection_url = string_concat("", url);
	connection_url = string_concat(connection_url, (string) "/v2/keys");
	connection_url = string_concat(connection_url, key);
	char *headers[2] = { "\0" };
	char *body[2] = { "\0" };
	char *response = http_request("GET", connection_url, headers, body);
	int response_body_begin_index = string_index(response, (string) "{", 1);
	int response_length = length_pointer_char(response);
	char *result = string_from_to(response, response_body_begin_index, response_length - 1);
	JSON_Value *root_value = json_parse_string(result);
	JSON_Object *root_object = json_value_get_object(root_value);
	JSON_Object *node_object = json_object_get_object(root_object, (string) "node");
	string value_result = (string) json_object_get_string(node_object, (string) "value");
	return value_result;
}

/**
 * Etcd Set
 * @param host
 * @param key
 * @param value
 * @return json
 */
int etcd_set(char *url, char *key, char *value) {
	
	if (!is_url(url) || is_empty(key) || is_empty(value)) {
		return FALSE;
	}
	
	char *path_to_key = string_concat("/v2/keys", key);
	char *connection_url;
	asprintf(&connection_url, "%s", url);
	if (string_index(path_to_key, "/", 1) < 0) {
		connection_url = string_concat(url, "/");
	}
	connection_url = string_concat(connection_url, path_to_key);
	char *header[2] = {
		"Content-Type: application/x-www-form-urlencoded",
		'\0'
	};
	
	char *body_message = "value=";
	body_message = string_concat(body_message, value);
	char *body[2] = {
		body_message,
		'\0'
	};
	
	char *response = http_request("PUT", connection_url, header, body);
	int response_body_begin_index = string_index(response, "{", 1);
	int response_length = length_pointer_char(response);
	char *result = string_from_to(
		response,
		response_body_begin_index,
		response_length - 1);
	if (is_empty(result)) {
		return FALSE;
	}
	JSON_Value *root_value = json_parse_string(result);
	JSON_Object *root_object = json_value_get_object(root_value);
	JSON_Object *node_object = json_object_get_object(root_object, "node");
	const char *value_result = json_object_get_string(node_object, "value");
	const char *key_result = json_object_get_string(node_object, "key");
	if (strcmp(value_result, value) != 0 || strcmp(key_result, key) != 0) {
		return FALSE;
	}
	return TRUE;
}
