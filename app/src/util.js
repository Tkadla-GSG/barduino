import { OPEN, CLOSE, MESSAGE, SEND } from 'redux-websocket-bridge';

const WEBSOCKET_PREFIX = '@@websocket/';

export const WEBSOCKET_OPEN = WEBSOCKET_PREFIX + OPEN;
export const WEBSOCKET_CLOSE = WEBSOCKET_PREFIX + CLOSE;
export const WEBSOCKET_MESSAGE = WEBSOCKET_PREFIX + MESSAGE;
export const WEBSOCKET_SEND = WEBSOCKET_PREFIX + SEND;

export const createWebsocketSendAction = payload => ({
    type: WEBSOCKET_SEND,
    payload,//: JSON.stringify(payload),
})