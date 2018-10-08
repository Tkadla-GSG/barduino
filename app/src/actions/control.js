import { createWebsocketSendAction } from '../util';

export const motorOff = id => dispatch => dispatch(createWebsocketSendAction('off_' + id));

export const motorLoad = id => dispatch => dispatch(createWebsocketSendAction('load_' + id));

export const motorUnload = id => dispatch => dispatch(createWebsocketSendAction('unload_' + id));